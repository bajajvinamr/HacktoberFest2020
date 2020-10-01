import os
import webbrowser
import sys
from colorama import Fore, Back, Style
from colorama import init
init()
#os.environ["HTTPS_PROXY"] = "http://username:pass@192.168.1.107:3128"
import requests
from bs4 import BeautifulSoup
import time
headers = {'user-agent': 'Mozbilla/5.0 (Macintosh; Intel Mac OS X 10_11_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36'}

query=""
#query = raw_input('What do you want to search on quora ? :    ')
for i in range(1,len(sys.argv)):
	query =query + sys.argv[i]+" "
print 'Searching '+ query
query.replace(" ",'+')
url = 'https://www.quora.com/search?q='+query
r = requests.get(url,headers=headers, timeout=15)
soup=BeautifulSoup(r.text,'lxml')

query_details=soup.find_all('span',{'class':'search_result_snippet'})


query_detail=[]
for x in query_details:
	query_detail.append(x)




ques_list= soup.find_all('div',{'class':'title'})
headlines = [x.text for x in ques_list]
for i in range(len(headlines)):
	print str(i+1)+". "+headlines[i]
while(1):
	choice = raw_input("Select your choice no:  ")
	href=ques_list[int(choice)-1].find('a').get('href')
	href="https://www.quora.com"+href
	print href
	print query_detail[int(choice)-1].text
	#print query_detail[int(choice)-1].find('span',{'class':'NameCredential IdentityNameCredential'}).text

	open_browser=raw_input("View in Detail. Open in browser y/n : ")
	if(open_browser.lower()=='y'):
		
		webbrowser.open(href)
	exit=raw_input("Press c or ctrl+c to exit: \nPress any random alphabet to select another headlines: ").lower()
	if(exit=='c'):
		exit()	
	
