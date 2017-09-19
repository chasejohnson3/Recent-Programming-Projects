# from bs4 import BeautifulSoup
# import urllib2
#
#
# def get_html_page_dom(url):
#     response = urllib2.urlopen(url)
#     html_doc = response.read()
#     return BeautifulSoup(html_doc, 'html5lib')
#
#
# def extract_rows(dom):
#     table_rows = dom.select('.mod-content tbody tr')
#
#     for tr in table_rows:
#         #  skip headers
#         klass = tr.get('class')
#         if klass is not None and 'colhead' in klass:
#             continue
#         tds = tr.select('td')
#         yield {'RK': tds[0].string,
#                'PLAYER': tds[1].select('a')[0].string,
#                'TEAM': tds[2].string,
#                'GP': tds[3].string
#                # you can fetch rest of the indexs for corresponding headers
#                }
#
# if __name__ == '__main__':f
#     dom = get_html_page_dom('http://espn.go.com/nba/statistics/player/_/stat/scoring-per-48-minutes/')
#     for data in extract_rows(dom):
#         print(data)
import bs4
from urllib.request import urlopen as uReq
from bs4 import BeautifulSoup as soup

#my_url = 'https://www.bing.com/search?q=google&form=PRDLC1&src=IE11TR&pc=EUPP_DCTE'
#my_url  = 'http://mlb.mlb.com/stats/sortable.jsp#elem=%5Bobject+Object%5D&tab_level=child&click_text=Sortable+Player+hitting&game_type='R'&season=2017&season_type=ANY&league_code=\'MLB\'&sectionType=sp&statType=hitting&page=1&ts=1505771915416'
my_url = 'http://www.newegg.com/Video-Cards-Video-Devices/Category/ID-38?Tpk=graphics%20card'
#opening connection, grabbing the page
uClient = uReq(my_url)
page_html = uClient.read()
uClient.close()

# html parser
page_soup = soup(page_html, "html.parser")
# print(page_soup.h1)
# print("\n")
# print(page_soup.p)
containers = page_soup.findAll("div", {"class":"item-container"})
# print(len(containers))
for container in containers:
    print("Brand: " + container.div.div.a.img["title"])
    print("Product: " + container.a.img["title"])
    shipping_container = container.findAll("li", {"class": "price-ship"})
    print("Shipping: " + shipping_container[0].text.strip() + "\n")

