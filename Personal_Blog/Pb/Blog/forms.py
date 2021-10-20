from django import forms
from .models import Contact

class Login(forms.ModelForm):
    class Meta:
        model = Contact
        fields = []