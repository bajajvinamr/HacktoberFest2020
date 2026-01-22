from django.contrib import admin
from django.urls import path, include
from . import views
from django.conf import settings
from django.conf.urls.static import static
from django.views.static import serve
from django.conf.urls import url

admin.site.site_header = "My Blog"
admin.site.index_title = "Welcome to My Blog"

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.index, name='Home'),
    path('signup', views.handleSignUp, name="handleSignUp"),
    path('login', views.handleLogin, name="handleLogin"),
    path('logout', views.handleLogout, name="handleLogout"),
    path('courses', views.courses, name='courses'),
    path('main', views.main, name='main'),
    path('asd', views.asd, name='asd'),
    path('Blog/', include('Blog.urls')),
    path('chat/', include('chat.urls')),
    url(r'^download/(?P<path>.*)$', serve, {'document root': settings.MEDIA_ROOT}),
    url(r'^media/(?P<path>.*)$', serve, {'document_root': settings.MEDIA_ROOT}),
    url(r'^static/(?P<path>.*)$', serve, {'document_root': settings.STATIC_ROOT}),

] + static(settings.MEDIA_URL, document_root =settings.MEDIA_ROOT)
