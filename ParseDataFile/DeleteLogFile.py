import os,re,datetime,time

regex=r'Data_\d+_\d{14}.dat$'

DataLogPath='D:\data\log'

wd_30s_MaxNum=50
n_30s=0

wd_1min_MaxNum=50
n_1min=0

wd_30min_MaxNum=50
n_30min=0

wd_over30min_MaxNum=50
n_over30min=0

for root, dirs, files in os.walk(DataLogPath):
    newFiles = sorted(files, reverse=True)

for file in newFiles:
    if not re.match(regex,file) == None:
        a,b,c = file.split('_',2)
        
        if( int(b)<30 ):
            n_30s += 1
            if( n_30s>wd_30s_MaxNum ):
                print('<30s:delete '+file)
                os.remove(DataLogPath+'\\'+file)

        elif( int(b)<=60 ):
            n_1min += 1
            if( n_1min>wd_1min_MaxNum ):
                print('<60s:delete '+file)
                os.remove(DataLogPath+'\\'+file)

        elif( int(b)<=1800 ):
            n_30min += 1
            if( n_30min>wd_30min_MaxNum ):
                print('<1800s:delete '+file)
                os.remove(DataLogPath+'\\'+file)

        else:
            n_over30min += 1
            if( n_over30min>wd_over30min_MaxNum ):
                print('>=1800s:delete '+file)
                os.remove(DataLogPath+'\\'+file)

