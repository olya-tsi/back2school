from selenium import webdriver
import time
import math

# Practice for JS code execution

link = "http://suninjuly.github.io/execute_script.html"

try:
    browser = webdriver.Chrome()
    browser.get(link)

    x_element = browser.find_element_by_id("input_value")
    x = x_element.text

    calc = lambda x: str(math.log(abs(12*math.sin(int(x)))))
    y = calc(x)

    answer = browser.find_element_by_id("answer")
    answer.send_keys(y)

    checkbox = browser.find_element_by_css_selector("input[id=\"robotCheckbox\"][type=checkbox]")
    checkbox.click()

    radiobutton = browser.find_element_by_css_selector("input[id=\"robotsRule\"][type=radio]")
    browser.execute_script("return arguments[0].scrollIntoView(true);", radiobutton)
    radiobutton.click()

    submit_button = browser.find_element_by_css_selector("button.btn")
    submit_button.click()

finally:
    time.sleep(30)
    browser.quit()