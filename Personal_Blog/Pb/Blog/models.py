from django.contrib.auth.models import User
from django.db import models
from django.utils.timezone import now


class Blogpost(models.Model):
    post_id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=50)
    head0 = models.CharField(max_length=500, default="")
    chead0 = models.CharField(max_length=5000, default="")
    head1 = models.CharField(max_length=500, default="")
    chead1 = models.CharField(max_length=5000, default="")
    head2 = models.CharField(max_length=500, default="")
    chead2 = models.CharField(max_length=5000, default="")
    desc = models.CharField(max_length=500000, default="")
    pub_date = models.DateField()
    file = models.FileField(upload_to='media', default='')


    def __str__(self):
        return self.title

class Contact(models.Model):
    msg_id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=50)
    email = models.CharField(max_length=70, default="")
    phone = models.CharField(max_length=70, default="")
    password = models.CharField(max_length=50, default='')

    def __str__(self):
        return self.name

class ml(models.Model):
    ml_id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=5000)
    algo = models.TextField(default="")
    img = models.ImageField(upload_to="blog/images", default="")
    video = models.URLField(default="")

    def __str__(self):
        return self.title


class web(models.Model):
    web_id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=5000)
    algo = models.TextField(max_length=900000, default="")
    img = models.ImageField(upload_to = "blog/images", default="")
    video = models.URLField(default="")
    file = models.FileField(upload_to='media', default='')

    def __str__(self):
        return self.title


class app(models.Model):
    app_id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=5000)
    algo = models.TextField(max_length=900000, default="")
    img = models.ImageField(upload_to="blog/images", default="")
    video = models.URLField(default="")
    file = models.FileField(upload_to='media', default='')

    def __str__(self):
        return self.title

class dsa(models.Model):
    dsa_id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=5000)
    algo = models.TextField(max_length=900000, default="")
    features = models.TextField(max_length=900000, default="")
    operations = models.TextField(max_length=900000, default="")
    img = models.ImageField(upload_to = "blog/images", default="")
    video = models.URLField(default="")
    file = models.FileField(upload_to='media', default='')

    def __str__(self):
        return self.title

class ai(models.Model):
    ai_id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=5000)
    algo = models.TextField(max_length=900000, default="")
    img1 = models.ImageField(upload_to = "blog/images", default="")
    img2 = models.ImageField(upload_to="blog/images", default="")
    img3 = models.ImageField(upload_to="blog/images", default="")
    img4 = models.ImageField(upload_to="blog/images", default="")
    img5 = models.ImageField(upload_to="blog/images", default="")
    file = models.FileField(upload_to='media', default='')

    video = models.URLField(default="")

    def __str__(self):
        return self.title


