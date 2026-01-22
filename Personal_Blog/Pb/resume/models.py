from django.db import models

class Music(models.Model):
    name = models.CharField(max_length=1000, default="")
    song = models.FileField(blank=True, null=True)
    artist = models.CharField(max_length=1000, default="")
    img = models.ImageField(upload_to='media', default=" ")

    def __str__(self):
        return self.name
