from selenium import webdriver
import time
import os

# Practice with attaching files

link = "http://suninjuly.github.io/file_input.html"

try:
    browser = webdriver.Chrome()
    browser.get(link)

    firstname = browser.find_element_by_css_selector("input[name=firstname]")
    firstname.send_keys("Ivan")
    lastname = browser.find_element_by_css_selector("input[name=lastname]")
    lastname.send_keys("Petrov")
    email = browser.find_element_by_css_selector("input[name=email]")
    email.send_keys("ipetr@mail.ru")

    curdir = os.path.abspath(os.path.dirname(__file__))
    file_path = os.path.join(curdir, 'useless.txt')

    file_input = browser.find_element_by_css_selector("input[type=file]")
    file_input.send_keys(file_path)

    submit_button = browser.find_element_by_css_selector("button.btn")
    submit_button.click()

finally:
    time.sleep(30)
    browser.quit()