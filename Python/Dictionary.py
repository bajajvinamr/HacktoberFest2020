#Dictionary
#beginner

pydic = {
    "apple" : "a fruit, usually green or red in color. The one Eve ate.",
    "lebanon" : "the place that got blasted a few weeks ago.",
    "pandemic" : "a new word nigerian youths learnt because of corona virus",
    "ncdc" : "a governemental parastatal we just heard about, as per covid.",
    "nddc" : "a governemtal parastatal that has been embezzling since the ages.",
}

print('Welcome to PyDic')
keyword = input('Enter Word to be searched: ')
print('Searching..........')

if keyword in pydic:
    print(pydic[keyword])
else:
    print('Sorry. Word not in pyDic')