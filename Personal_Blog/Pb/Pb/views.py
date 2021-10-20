from django.contrib import messages
from django.contrib.auth import logout, authenticate, login
from django.contrib.auth.models import User
from django.shortcuts import render, redirect

from django.http import HttpResponse

def index(request):
    return render(request, 'index.html')


def courses(request):
    return render(request, 'courses.html')

def asd(request):
    return render(request, 'asd.html')
def main(request):
    return render(request, 'main.html')


def handleSignUp(request):
    if request.method == "POST":
        # Get the post parameters
        username = request.POST['username']
        email = request.POST['email']
        fname = request.POST['fname']
        lname = request.POST['lname']
        pass1 = request.POST['pass1']
        pass2 = request.POST['pass2']

        # check for errorneous input

        # Create the user
        myuser = User.objects.create_user(username, email, pass1)
        myuser.first_name = fname
        myuser.last_name = lname
        myuser.save()
        messages.success(request, " Your account has been successfully created")
        return redirect('main')

    else:
        return HttpResponse("404 - Not found")

    return HttpResponse("login")

def handleLogin(request):
    if request.method == "POST":
        # Get the post parameters
        loginusername = request.POST['loginusername']
        loginpassword = request.POST['loginpassword']

        user = authenticate(username = loginusername, password = loginpassword)

        if user is not None:
            login(request, user)
            messages.success(request, "Successfully loged in")
            return redirect('main')
        else:
            messages.error(request, "Invalid, Try Again")
            return redirect("Blog/Contact")

    return HttpResponse("handlelogin")

def handleLogout(request):
    logout(request)
    messages.success(request, "Successfully logged out")
    return redirect('/')
