from selenium import webdriver
import time
import math

# Practice with pop-up window

link = "http://suninjuly.github.io/alert_accept.html"

try:
    browser = webdriver.Chrome()
    browser.get(link)

    button = browser.find_element_by_css_selector("button.btn.btn-primary")
    button.click()

    confirm_wnd = browser.switch_to.alert
    confirm_wnd.accept()

    calc = lambda x: str(math.log(abs(12*math.sin(int(x)))))
    x_element = browser.find_element_by_id("input_value")
    x = x_element.text
    y = calc(x)

    answer = browser.find_element_by_id("answer")
    answer.send_keys(y)

    submit_button = browser.find_element_by_css_selector("button.btn")
    submit_button.click()

finally:
    time.sleep(30)
    browser.quit()