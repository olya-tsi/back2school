from selenium import webdriver
import time
import math

# Practice with tabs

link = "http://suninjuly.github.io/redirect_accept.html"
try:
    browser = webdriver.Chrome()
    browser.get(link)

    redirect_button = browser.find_element_by_css_selector("button.btn.btn-primary")
    redirect_button.click()

    new_window = browser.window_handles[1]
    browser.switch_to.window(new_window)

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