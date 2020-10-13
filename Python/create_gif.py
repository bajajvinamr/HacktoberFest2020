import os
import imageio


def create_gif(dir_path, gif_name):
    """
    Creates a gif using the images found in dir_path.
    Works with JPG & PNG. Images are sorted by filename

    Arguments:
        dir_path: Path to the directory containing
                  the images
        gif_name: Name of the gif file you want 
                  to create.
    """
    images = []
    for file in sorted(os.listdir(dir_path)):
        filepath = os.path.join(dir_path, file)
        images.append(imageio.imread(filepath))

    imageio.mimwrite(gif_name, images, format='GIF')


if __name__ == '__main__':
    dir_path = 'ENTER YOUR DIRECTORY HERE'
    create_gif(dir_path, 'example.gif')