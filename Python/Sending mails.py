import smtplib,ssl
port=587
smtp_server="smtp.gmail.com"
sender="testmail02082020@gmail.com"
receiver=["ritika@xyz.com","suman@abc.com"]
pswd=input("Enter your password ")
message="""Subject:test mail
this is a test mail from python"""
context=ssl.create_default_context()
with smtplib.SMTP(smtp_server,port,) as server:
    server.starttls(context=context)
    server.ehlo
    server.login(sender,pswd)
    server.sendmail(sender,receiver,message)
