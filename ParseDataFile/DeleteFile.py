import os,re,datetime,time

regex=r'Data_\d+_\d{14}.dat$'

DataLogPath='E:\wangdi\data'

for root, dirs, files in os.walk(DataLogPath):
    newFiles = sorted(files, reverse=True)

for file in newFiles:
	print(file)
	os.remove(DataLogPath+'\\'+file)

