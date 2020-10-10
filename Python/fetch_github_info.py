import requests

_GITHUB_API = "https://api.github.com/user"


def fetch_github_info(auth_user, auth_pass):
    """
    Fetch GitHub info of a user using the requests module
    """
    return requests.get(_GITHUB_API, auth=(auth_user, auth_pass)).json()


if __name__ == "__main__":
    for key, value in fetch_github_info("<USERNAME>", "<PASSWORD>").items():
        print(key,value)
