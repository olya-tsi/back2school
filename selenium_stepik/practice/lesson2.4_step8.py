from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium import webdriver
import time
import math

# Practice with explicit waits

link = "http://suninjuly.github.io/explicit_wait2.html"
try:
    browser = webdriver.Chrome()
    browser.get(link)

    book_button = browser.find_element_by_css_selector("button.btn[id=book]")
    price = WebDriverWait(browser, 12).until(
        EC.text_to_be_present_in_element((By.CSS_SELECTOR, "h5[id=price]"), "$100")
    )
    book_button.click()

    calc = lambda x: str(math.log(abs(12*math.sin(int(x)))))
    x_element = browser.find_element_by_id("input_value")
    x = x_element.text
    y = calc(x)

    answer = browser.find_element_by_id("answer")
    answer.send_keys(y)

    submit_button = WebDriverWait(browser, 5).until(
        EC.element_to_be_clickable((By.ID, "solve"))
    )
    submit_button.click()

finally:
    time.sleep(30)
    browser.quit()

