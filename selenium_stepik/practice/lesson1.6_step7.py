from selenium import webdriver
import time


link = "http://suninjuly.github.io/huge_form.html"

try:
    browser = webdriver.Chrome()
    browser.get(link)

    inputs = browser.find_elements_by_tag_name("input")
    for inp in inputs:
        inp.send_keys("Not empty")

    submit_btn = browser.find_element_by_css_selector("button.btn-default")
    submit_btn.click()

finally:
    time.sleep(30)
    browser.quit()