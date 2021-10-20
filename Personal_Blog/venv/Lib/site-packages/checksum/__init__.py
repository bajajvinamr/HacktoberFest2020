"""
    Creates checksums for files and directories.

    Homepage:
        https://github.com/hweickert/checksum

    Based on:
        https://github.com/cakepietoast/checksumdir

    Supports optional dot-directory filtering and custom filter functions.


    Usage:
        >>> import checksum
        >>> checksum.get_for_file( "/some_directory/some_file.txt" )
        >>> checksum.get_for_directory( "/some_directory" )
"""

import sys
import os
import hashlib
import re
import itertools

_PY2 = sys.version_info.major == 2

if _PY2:
    from itertools import imap
else:
    imap=map

if _PY2:
    from itertools import ifilterfalse
else:
    ifilterfalse=itertools.filterfalse

_HASH_MODE_DICT = {
    "md5": hashlib.md5,
    "sha1": hashlib.sha1,
    "sha256": hashlib.sha256,
    "sha512": hashlib.sha512
}

def get_for_directory(
        dp,
        hash_mode="md5",
        filter_dots=False,
        filter_func=lambda fp:False
    ):
    r"""
        Returns a hash string for the files below a given directory path.

        :param dp:          Path to a directory.
        :param hash_mode:   Can be either one of 'md5', 'sha1', 'sha256' or 'sha512'.
                            Defines the algorithm used to generate the resulting hash
                            string. Default is 'md5'.
        :param filter_dots: If True will filter directories or files beginning with a '.' (dot) like '.git'.
                            Default is False.
        :param filter_func: A function receiving a path as a single paramter. If it returns True the given
                            path will be excluded from the hash calculation. Otherwise it will be included.
    """

    hash_func = _HASH_MODE_DICT.get(hash_mode)

    root_dps_fns =      os.walk( dp, topdown=True )
    root_dps_fns =      imap(         list,                  root_dps_fns )
    if filter_dots:
        root_dps_fns =  ifilterfalse( _is_dot_root,           root_dps_fns )
        root_dps_fns =  imap(         _filter_dot_fns,        root_dps_fns )
    fps_lists =         imap(         _gen_fps,               root_dps_fns )
    fps =               itertools.chain(        *fps_lists )
    fps =               ifilterfalse( filter_func,           fps )
    file_handles =      imap(         _get_file_handle,      fps )
    file_hash_digests = imap(         _get_file_hash_digest, file_handles, itertools.repeat(hash_func) )
    file_hash_digests = sorted( file_hash_digests )
    file_hash_digests = map(    _get_utf8_encoded, file_hash_digests )

    hash_ = _get_merged_hash( file_hash_digests, hash_func )

    return hash_.hexdigest()



def get_for_file( fp, hash_mode="md5" ):
    r"""
        Returns a hash string for the given file path.

        :param fp:          Path to the file.
        :param hash_mode:   Can be either one of 'md5', 'sha1', 'sha256' or 'sha512'.
                            Defines the algorithm used to generate the resulting hash
                            string. Default is 'md5'.
    """

    with _get_file_handle(fp) as f:
        file_hash_digest = get_for_handle(f, hash_mode)

        return file_hash_digest



def get_for_handle( f, hash_mode="md5" ):
    r"""
        Returns a hash string for the given file-like object.

        :param f:           The file object.
        :param hash_mode:   Can be either one of 'md5', 'sha1', 'sha256' or 'sha512'.
                            Defines the algorithm used to generate the resulting hash
                            string. Default is 'md5'.
    """

    hash_func = _HASH_MODE_DICT.get(hash_mode)
    file_hash_digest = _get_file_hash_digest( f, hash_func )
    file_hash_digest = _get_utf8_encoded( file_hash_digest )
    return file_hash_digest


def _get_file_hash_digest( file_handle, hash_func ):
    result = hash_func()
    blocksize = 64 * 1024
    while True:
        data = file_handle.read(blocksize)
        if not data:
            break
        result.update(data)
    return result.hexdigest()



def _is_dot_root( root_dps_fns ):
    return re.search( r"[\\/]\.", root_dps_fns[0] ) is not None



def _filter_dot_fns( root_dps_fns ):
    root_dps_fns[2] = ifilterfalse( lambda fn: fn.startswith('.'), root_dps_fns[2] )
    return root_dps_fns



def _gen_fps( root_dps_fns ):
    for fn in root_dps_fns[2]:
        yield os.path.join(root_dps_fns[0], fn)


def _get_utf8_encoded( hash_digest ):
    if _PY2:
        return hash_digest.encode( 'utf-8' )
    else:
        hash_encoded = hash_digest.encode( 'utf-8' )
        return str(hash_encoded, 'utf-8')



def _get_merged_hash(hash_digests, hashfunc):
    result = hashfunc()
    for digest in hash_digests:
        result.update(digest.encode('utf-8'))
    return result


def _get_file_handle( fp ):
    return open(fp, 'rb')
