import json
import urllib.request,urllib.parse,urllib.error
import ssl

ctx = ssl.create_default_context
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input("enter :")

uh = urllib.request.urlopen(url,context=ctx)
rawdata = uh.read().decode()

data = json.loads(rawdata)

print(json.dumps(data,indent=3))
count = 0
for item in data['comments']:
    count += int(item['count'])
print(count)    
