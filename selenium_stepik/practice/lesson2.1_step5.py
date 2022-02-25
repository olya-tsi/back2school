from selenium import webdriver
import time
import math

# Practice for working with checkboxes adn radiobuttons

def calc(x):
    return str(math.log(abs(12*math.sin(int(x)))))

link = "http://suninjuly.github.io/math.html"

try:
    browser = webdriver.Chrome()
    browser.get(link)

    x_element = browser.find_element_by_id("input_value")
    x = x_element.text
    y = calc(x)

    answer = browser.find_element_by_id("answer")
    answer.send_keys(y)

    checkbox = browser.find_element_by_css_selector("input[id=\"robotCheckbox\"][type=checkbox]")
    checkbox.click()

    radiobutton = browser.find_element_by_css_selector("input[id=\"robotsRule\"][type=radio]")
    radiobutton.click()

    submit_button = browser.find_element_by_css_selector("button.btn")
    submit_button.click()


finally:
    time.sleep(30)
    browser.quit()