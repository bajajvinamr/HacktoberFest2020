from django.contrib import admin
from django.urls import path, include
from . import views


urlpatterns = [

    path('p/', views.index, name="index"),
    path('p/blogpost/<int:id>', views.blogpost ,name="blogPost"),
    path('Contact', views.contact, name="contact"),
    path('about', views.about, name="about"),

    path('mlindex/', views.mlindex, name="mlindex"),
    path('mlindex/mlt/<int:id>', views.mlt, name="mlt"),

    path('appindex/', views.appindex, name="appindex"),
    path('appindex/appt/<int:id>', views.appt, name="apptt"),

    path('webindex/', views.webindex, name="webindex"),
    path('webindex/webt/<int:id>', views.webt, name="webt"),

    path('dsaindex/', views.dsaindex, name="dsaindex"),
    path('dsaindex/dsat/<int:id>', views.dsat, name="dsat"),

    path('aindex/', views.aindex, name="aindex"),
    path('aindex/ait/<int:id>', views.ait, name="ait"),
    path('search/', views.search, name="search"),

]
