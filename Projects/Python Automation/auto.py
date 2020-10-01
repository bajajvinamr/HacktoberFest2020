from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

import os
import json
import time
import datetime

now = datetime.datetime.now()
today = datetime.datetime.now().strftime("%A")
sunday = {
    "sub1": "Physics", "sub1_teacher": "KG", "sub1_start": now.replace(hour=9, minute=0), "sub1_end": now.replace(hour=9, minute=45),
    "sub2": "Maths", "sub2_teacher": "NVP", "sub2_start": now.replace(hour=10, minute=15), "sub2_end": now.replace(hour=11, minute=0),
    "sub3": "Chem", "sub3_teacher": "RT", "sub3_start": now.replace(hour=11, minute=15), "sub3_end": now.replace(hour=12, minute=0),
    "sub4": "Further", "sub4_teacher": "", "sub4_start": now.replace(hour=12, minute=30), "sub4_end": now.replace(hour=13, minute=15),
    "sub5": "Chem", "sub5_teacher": "ShT", "sub5_start": now.replace(hour=13, minute=30), "sub5_end": now.replace(hour=14, minute=15)}
monday = {
    "sub1": "English", "sub1_teacher": "", "sub1_start": now.replace(hour=8, minute=0), "sub1_end": now.replace(hour=8, minute=45),
    "sub2": "Further", "sub2_teacher": "", "sub2_start": now.replace(hour=9, minute=0), "sub2_end": now.replace(hour=9, minute=45),
    "sub3": "Chem", "sub3_teacher": "ShT", "sub3_start": now.replace(hour=11, minute=15), "sub3_end": now.replace(hour=12, minute=0)}
tuesday = {
    "sub1": "Physics", "sub1_teacher": "DPK-Not sure", "sub1_start": now.replace(hour=8, minute=0), "sub1_end": now.replace(hour=8, minute=45),
    "sub2": "Chem", "sub2_teacher": "RT", "sub2_start": now.replace(hour=9, minute=0), "sub2_end": now.replace(hour=9, minute=45),
    "sub3": "Chem", "sub3_teacher": "UVK", "sub3_start": now.replace(hour=10, minute=15), "sub3_end": now.replace(hour=11, minute=0),
    "sub4": "Maths", "sub4_teacher": "TKL", "sub4_start": now.replace(hour=11, minute=15), "sub4_end": now.replace(hour=12, minute=0),
    "sub5": "Physics", "sub5_teacher": "HRT", "sub5_start": now.replace(hour=12, minute=30), "sub5_end": now.replace(hour=13, minute=15),
    "sub6": "Further", "sub6_teacher": "", "sub6_start": now.replace(hour=13, minute=30), "sub6_end": now.replace(hour=14, minute=15)}
wednesday = {
    "sub1": "English", "sub1_teacher": "", "sub1_start": now.replace(hour=8, minute=0), "sub1_end": now.replace(hour=8, minute=45),
    "sub2": "Maths", "sub2_teacher": "AKC-Mechanics", "sub2_start": now.replace(hour=9, minute=0), "sub2_end": now.replace(hour=9, minute=45),
    "sub3": "Chem", "sub3_teacher": "RT", "sub3_start": now.replace(hour=10, minute=15), "sub3_end": now.replace(hour=11, minute=0),
    "sub4": "Physics", "sub4_teacher": "SuB", "sub4_start": now.replace(hour=11, minute=15), "sub4_end": now.replace(hour=12, minute=0),
    "sub5": "Further", "sub5_teacher": "", "sub5_start": now.replace(hour=12, minute=30), "sub5_end": now.replace(hour=13, minute=15), }
thursday = {
    "sub1": "Chem", "sub1_teacher": "DPK", "sub1_start": now.replace(hour=9, minute=0), "sub1_end": now.replace(hour=9, minute=45),
    "sub2": "Maths", "sub2_teacher": "TKL", "sub2_start": now.replace(hour=11, minute=15), "sub2_end": now.replace(hour=12, minute=0),
    "sub3": "Physics", "sub3_teacher": "KG", "sub3_start":  now.replace(hour=12, minute=30), "sub3_end": now.replace(hour=13, minute=15),
    "sub4": "Maths", "sub4_teacher": "NVP", "sub4_start": now.replace(hour=13, minute=30), "sub4_end": now.replace(hour=14, minute=15), }
friday = {
    "sub1": "Physics", "sub1_teacher": "HRT", "sub1_start": now.replace(hour=8, minute=0), "sub1_end": now.replace(hour=8, minute=45),
    "sub2": "Further", "sub2_teacher": "", "sub2_start": now.replace(hour=10, minute=15), "sub2_end": now.replace(hour=11, minute=0),
    "sub3": "English", "sub3_teacher": "", "sub3_start": now.replace(hour=12, minute=30), "sub3_end": now.replace(hour=13, minute=15),
    "sub4": "Chem", "sub4_teacher": "RT", "sub4_start": now.replace(hour=13, minute=30), "sub4_end": now.replace(hour=14, minute=15), }


class MyHandler(FileSystemEventHandler):
    def on_modified(self, event):
        for filename in os.listdir(folder_to_track):
            src = folder_to_track + "/" + filename
            sub = ""
            teacher = ""
            now = datetime.datetime.now()
            if today == "Sunday":
                if sunday["sub1_start"] < now < sunday["sub1_end"]:
                    sub = sunday["sub1"]
                    teacher = sunday["sub1_teacher"]
                elif sunday["sub2_start"] < now < sunday["sub2_end"]:
                    sub = sunday["sub2"]
                    teacher = sunday["sub2_teacher"]
                elif sunday["sub3_start"] < now < sunday["sub3_end"]:
                    sub = sunday["sub3"]
                    teacher = sunday["sub3_teacher"]
                elif sunday["sub4_start"] < now < sunday["sub4_end"]:
                    sub = sunday["sub4"]
                    teacher = sunday["sub4_teacher"]
                elif sunday["sub5_start"] < now < sunday["sub5_end"]:
                    sub = sunday["sub5"]
                    teacher = sunday["sub5_teacher"]
            elif today == "Monday":
                if monday["sub1_start"] < now < monday["sub1_end"]:
                    sub = monday["sub1"]
                    teacher = monday["sub1_teacher"]
                elif monday["sub2_start"] < now < monday["sub2_end"]:
                    sub = monday["sub2"]
                    teacher = monday["sub2_teacher"]
                elif monday["sub3_start"] < now < monday["sub3_end"]:
                    sub = monday["sub3"]
                    teacher = monday["sub3_teacher"]
            elif today == "Tuesday":
                if tuesday["sub1_start"] < now < tuesday["sub1_end"]:
                    sub = tuesday["sub1"]
                    teacher = tuesday["sub1_teacher"]
                elif tuesday["sub2_start"] < now < tuesday["sub2_end"]:
                    sub = tuesday["sub2"]
                    teacher = tuesday["sub2_teacher"]
                elif tuesday["sub3_start"] < now < tuesday["sub3_end"]:
                    sub = tuesday["sub3"]
                    teacher = tuesday["sub3_teacher"]
                elif tuesday["sub4_start"] < now < tuesday["sub4_end"]:
                    sub = tuesday["sub4"]
                    teacher = tuesday["sub4_teacher"]
                elif tuesday["sub5_start"] < now < tuesday["sub5_end"]:
                    sub = tuesday["sub5"]
                    teacher = tuesday["sub5_teacher"]
                elif tuesday["sub6_start"] < now < tuesday["sub6_end"]:
                    sub = tuesday["sub6"]
                    teacher = tuesday["sub6_teacher"]
            elif today == "Wednesday":
                if wednesday["sub1_start"] < now < wednesday["sub1_end"]:
                    sub = wednesday["sub1"]
                    teacher = wednesday["sub1_teacher"]
                elif wednesday["sub2_start"] < now < wednesday["sub2_end"]:
                    sub = wednesday["sub2"]
                    teacher = wednesday["sub2_teacher"]
                elif wednesday["sub3_start"] < now < wednesday["sub3_end"]:
                    sub = wednesday["sub3"]
                    teacher = wednesday["sub3_teacher"]
                elif wednesday["sub4_start"] < now < wednesday["sub4_end"]:
                    sub = wednesday["sub4"]
                    teacher = wednesday["sub4_teacher"]
                elif wednesday["sub5_start"] < now < wednesday["sub5_end"]:
                    sub = tuesday["sub5"]
                    teacher = tuesday["sub5_teacher"]
            elif today == "Thursday":
                if thursday["sub1_start"] < now < thursday["sub1_end"]:
                    sub = thursday["sub1"]
                    teacher = thursday["sub1_teacher"]
                elif thursday["sub2_start"] < now < thursday["sub2_end"]:
                    sub = thursday["sub2"]
                    teacher = thursday["sub2_teacher"]
                elif thursday["sub3_start"] < now < thursday["sub3_end"]:
                    sub = thursday["sub3"]
                    teacher = thursday["sub3_teacher"]
                elif thursday["sub4_start"] < now < thursday["sub4_end"]:
                    sub = thursday["sub4"]
                    teacher = thursday["sub4_teacher"]
            elif today == "Friday":
                if friday["sub1_start"] < now < friday["sub1_end"]:
                    sub = friday["sub1"]
                    teacher = friday["sub1_teacher"]
                elif friday["sub2_start"] < now < friday["sub2_end"]:
                    sub = friday["sub2"]
                    teacher = friday["sub2_teacher"]
                elif friday["sub3_start"] < now < friday["sub3_end"]:
                    sub = friday["sub3"]
                    teacher = friday["sub3_teacher"]
                elif friday["sub4_start"] < now < friday["sub4_end"]:
                    sub = friday["sub4"]
                    teacher = friday["sub4_teacher"]
            else:
                sub = "Screenshots"
                return sub, teacher

            if not os.path.isdir(folder_destination + "/" + sub + "/" + teacher + "/" + date):
                os.makedirs(folder_destination + "/" +
                            sub + "/" + teacher + "/" + date)
            else:
                print(folder_destination + " /" +
                      sub + "/" + teacher + "/" + date)
            new_destination = folder_destination + "/" + sub +\
                "/" + teacher + "/" + date + "/" + filename
            os.rename(src, new_destination)


today = datetime.datetime.now().strftime("%A")
date = datetime.datetime.today().strftime('%Y-%m-%d')
print(today, date)

folder_to_track = "/home/prastab/Pictures"
folder_destination = "/home/prastab/notes"

event_handler = MyHandler()
observer = Observer()

observer.schedule(event_handler, folder_to_track, recursive=True)
observer.start()
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    observer.stop()

observer.join()
