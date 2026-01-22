from django.contrib.auth import authenticate, logout, login
from django.shortcuts import render, redirect
from .models import Blogpost,Contact, ml, web, dsa, app, ai
from django.http import HttpResponse, Http404
from django.contrib import messages
from django.contrib.auth.models import User, auth


def home(request):
    return HttpResponse("home")

def about(request):
    return render(request, 'blog/about.html')


def search(request):
    query=request.GET['query']
    BlogPosts = Blogpost.objects.filter(title__icontains=query)
    mlPosts = ml.objects.filter(title__icontains=query)
    webPosts = web.objects.filter(title__icontains=query)
    params={'BlogPosts':BlogPosts, 'mlPosts':mlPosts, 'webPosts':webPosts}
    return render(request, 'blog/search.html', params)



def index(request):
    if request.method =="POST":
        file2 = request.FILES['files']
        document = Blogpost.objects.create(file= file2)
    myposts= Blogpost.objects.all()
    print(myposts)
    return render(request, 'blog/index.html', {'myposts': myposts})

def blogpost(request, id):
    post = Blogpost.objects.filter(post_id = id)[0]
    print(post)
    return render(request, 'blog/blogpost.html', {'post': post})


def contact(request):
    thank = False
    if request.method=="POST":
        name = request.POST.get('name', '')
        email = request.POST.get('email', '')
        phone = request.POST.get('phone', '')
        password = request.POST.get('password', '')
        contact = Contact(name=name, email=email, phone=phone, password=password)

        if Contact.objects.filter(email = email).exists():
            messages.add_message(request, 'Email Already Exists')

        elif Contact.objects.filter(name = name).exists():
            messages.info(request, 'Username Already Exists')

        else:
            contact.save()
            messages.add_message(request, messages.SUCCESS, "you are successfully registered")
        thank = True
    return render(request, 'blog/contact.html')


# ml
def mlindex(request):
    mlposts = ml.objects.all()
    print(mlposts)
    return render(request, 'blog/mlindex.html', {'mlposts': mlposts})
def mlt(request,id):
    mlpost = ml.objects.filter(ml_id = id)[0]
    print(mlpost)
    return render(request, 'blog/ml.html', {'mlpost': mlpost})


# web
def webindex(request):
    webposts = web.objects.all()
    return render(request, 'blog/webindex.html', {'webposts': webposts})

def webt(request,id):
    if request.method =="POST":
        file2 = request.FILES['files']
        document = web.objects.create(file= file2)
    webpost = web.objects.filter(web_id = id)[0]
    return render(request, 'blog/web.html', {'webpost': webpost})



#dsa

def dsaindex(request):
    dsaposts = dsa.objects.all()
    return render(request, 'blog/dsaindex.html', {'dsaposts': dsaposts})
def dsat(request,id):
    if request.method =="POST":
        file2 = request.FILES['files']
        document = dsa.objects.create(file= file2)
    dsapost = dsa.objects.filter(dsa_id = id)[0]
    return render(request, 'blog/dsa.html', {'dsapost': dsapost})


#app

def appindex(request):
    appposts = app.objects.all()
    return render(request, 'blog/appindex.html', {'appposts': appposts})
def appt(request,id):
    if request.method =="POST":
        file2 = request.FILES['files']
        document = app.objects.create(file= file2)
    apppost = app.objects.filter(app_id = id)[0]
    return render(request, 'blog/app.html', {'apppost': apppost})


#ai
def aindex(request):
    aiposts = ai.objects.all()
    return render(request, 'blog/aindex.html', {'aiposts': aiposts})
def ait(request,id):
    if request.method == "POST":
        file2 = request.FILES['files']
        document = app.objects.create(file=file2)
    aipost = ai.objects.filter(ai_id = id)[0]
    return render(request, 'blog/ai.html', {'aipost': aipost})

