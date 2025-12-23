#Website Blocker
#Many unwanted sites popup to distract us.  
#This project help peoples to block certain websites from opening who get easily distracted. 
from datetime import datetime as dt
import time
hosts_path = r"/etc/hosts"   
hosts_temp = "hosts"
redirect = "127.0.0.1"
web_block_list = ["www.xyz.com", "paisaxyz.com","youxyz.com"]  # users can update the list of the websites they want to block.
while True:
   if dt(dt.now().year, dt.now().month, dt.now().day, 9) < dt.now() < dt(dt.now().year, dt.now().month, dt.now().day,22):
       print("You are on Working hours")
       with open(hosts_path, "r+") as file:
           content = file.read()
           for website in web_block_list:
               if website in content:
                   pass
               else:
                   file.write(redirect+" "+website+"\n")
   else:
       print("You have Fun time... Enjoy!")
       with open(hosts_path, "r+") as file:
           content = file.readlines()
           file.seek(0) 
           for line in content:
               #we overwrite the whole file
               if not any(website in line for website in web_block_list):
                   file.write(line)
               #do nothing else
           file.truncate() #this line is used to delete the trailing lines
   time.sleep(5)
