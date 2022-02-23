from selenium import webdriver
import time
import math

# Practice for working with get_attribute method

link = "http://suninjuly.github.io/get_attribute.html"
try:
    browser = webdriver.Chrome()
    browser.get(link)

    treasure_el = browser.find_element_by_id("treasure")
    x = treasure_el.get_attribute("valuex")

    calc = lambda x: str(math.log(abs(12*math.sin(int(x)))))
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