# Generated by Django 3.2.6 on 2021-08-12 11:55

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Blog', '0019_auto_20210812_1633'),
    ]

    operations = [
        migrations.RenameField(
            model_name='ai',
            old_name='img',
            new_name='img1',
        ),
        migrations.AddField(
            model_name='ai',
            name='img2',
            field=models.ImageField(default='', upload_to='blog/images'),
        ),
        migrations.AddField(
            model_name='ai',
            name='img3',
            field=models.ImageField(default='', upload_to='blog/images'),
        ),
        migrations.AddField(
            model_name='ai',
            name='img4',
            field=models.ImageField(default='', upload_to='blog/images'),
        ),
        migrations.AddField(
            model_name='ai',
            name='img5',
            field=models.ImageField(default='', upload_to='blog/images'),
        ),
    ]
