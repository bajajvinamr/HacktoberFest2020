from django.db import models


class Room(models.Model):
    name = models.CharField(max_length=1000)

class Message(models.Model):
    value = models.CharField(max_length=1000000)
    username = models.CharField(max_length=1000000)
    room = models.CharField(max_length=1000000)