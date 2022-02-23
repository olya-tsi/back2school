from selenium import webdriver
import time

# Practice for JS code execution

try:
    browser = webdriver.Chrome()
    browser.execute_script("document.title='Script executing';alert('Robots at work');")

finally:
    time.sleep(30)
    browser.quit()