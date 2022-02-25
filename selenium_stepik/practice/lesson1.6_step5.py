from selenium import webdriver
import math
import time

link = "http://suninjuly.github.io/find_link_text"

try:
    browser = webdriver.Chrome()
    browser.get(link)

    # find secret link
    secret = str(math.ceil(math.pow(math.pi, math.e)*10000))
    secret_link = browser.find_element_by_link_text(secret)
    secret_link.click()

    # fill page form from secret link
    first_name = browser.find_element_by_tag_name("input")
    first_name.send_keys("Ivan")
    last_name = browser.find_element_by_name("last_name")
    last_name.send_keys("Petrov")
    city = browser.find_element_by_class_name("city.form-control")
    city.send_keys("Smolensk")
    country = browser.find_element_by_id("country")
    country.send_keys("Russia")
    submit_btn = browser.find_element_by_css_selector("button.btn-default")
    submit_btn.click()

finally:
    time.sleep(30)
    browser.quit()
