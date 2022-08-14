from bs4 import BeautifulSoup as bs
import requests as r
import sqlite3 as sq

def listdb(title, link):
    #import sqlite3 as sq
    #import time
    conn = sq.connect('list_of_links.db')
    cor = conn.cursor()
    cor.executescript("""CREATE TABLE IF NOT EXISTS links(
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        title TEXT unique,
        link TEXT""")
    cor.execute("""INSERT INTO links(title, link)
                values(?, ?)""", (title, link))
    conn.commit()
    return None
    
    
url = 'https://en.wikipedia.org/wiki/Lists_of_books'
site = r.get(url)
if site.status_code == 200:
    soup = bs(site.text, 'lxml')
    print(f'Status code: {site.status_code}')

main_div = soup.find('div', class_='div-col').ul
li = main_div.find_all('li')
#print(li)
for link in li:
    title = link.a.text
    link = 'https://en.wikipedia.org' + link.a['href']
    listdb(title, link)
    print(title, link)