import unittest
from selenium import webdriver
import time

# Practice with unittest framework
class TestRegistration(unittest.TestCase):
    def get_welcome_text(self, link):
        welcome_text = ''
        browser = webdriver.Chrome()
        browser.get(link)

        # fill required fields
        first_name = browser.find_element_by_css_selector("input[placeholder=\"Input your first name\"].first.form-control")
        first_name.send_keys("Ivan")
        second_name = browser.find_element_by_css_selector("input[placeholder=\"Input your last name\"].second.form-control")
        second_name.send_keys("Petrov")
        email = browser.find_element_by_css_selector("input[placeholder=\"Input your email\"].third.form-control")
        email.send_keys("ipetr@mail.ru")

        # send filled form
        button = browser.find_element_by_css_selector("button.btn")
        button.click()

        # wait page loading in case of successful registration
        time.sleep(1)

        # find element with welcome text
        welcome_text_elt = browser.find_element_by_tag_name("h1")
        welcome_text = welcome_text_elt.text

        browser.quit()

        return welcome_text

    def test_page1(self):
        link = "http://suninjuly.github.io/registration1.html"
        welcome_text = self.get_welcome_text(link)
        self.assertEqual(welcome_text, "Congratulations! You have successfully registered!", "Wrong welcome message after registration")

    def test_page2(self):
        link = "http://suninjuly.github.io/registration2.html"
        welcome_text = self.get_welcome_text(link)
        self.assertEqual(welcome_text, "Congratulations! You have successfully registered!", "Wrong welcome message after registration")


if __name__ == "__main__":
    unittest.main()