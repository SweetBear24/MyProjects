import csv
import os

def searchName():
     csv_file=csv.reader(open('currencies23.csv', 'r'))
     name=input('Введите название криптовалюты:\n')
     flag=0
     for row in csv_file:
         if name==row[0]:
             print(' Name     Symbol      Price       Market_cap')
             print(row)
             with open("log.txt", "a") as log:
                 log.writelines(s + ' ' for s in row)
                 log.write('\n')
                 log.close()
                 flag=1
             
     if flag == 0: 
          print('Нет такой криптовалюты!\n')
          with open("log.txt", "a") as log:
               log.write('Нет такой криптовалюты!\n')
               log.close()
          flag=0          
         
def showScrFile():
    csv_file=csv.reader(open('currencies23.csv', 'r'))
    print(' Name     Symbol      Price       Market_cap')
    for row in csv_file:
        print(row)
        
def checkFile():   
     if os.stat('log.txt').st_size > 0:
          delete=input('В файле есть данные. Хотите очистить файл? anykey/n\n')
          if delete == 'y':
               log=open('log.txt', 'w+')
               log.seek(0)
               log.close()
          else:
               with open("log.txt", "a") as log:
                    log.write('\nНовая запись:\n')
                    log.close()

def showLogFile():
     print('\n\t\tLOG FILE ')
     print('Name   Symbol    Price    Market_cap')
     with open('log.txt', 'r') as reader:
          for line in reader.readlines():
               print(line, end='')
     reader.close()

        
checkFile() 
showScrFile()

flag=''
while(flag!='n'):
    searchName()
    flag=input('Хотите продолжить? anykey/n \n')

showLogFile()
