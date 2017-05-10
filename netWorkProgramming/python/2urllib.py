import urllib
data = urllib.urlopen("http://www.baidu.com")

for eachLine in data:
    print eachLine
