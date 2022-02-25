from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
import math
import pytest

# Practice for pytest parametrize fixture

@pytest.fixture(scope="function")
def browser():
    print("\nstart browser for test..")
    browser = webdriver.Chrome()
    yield browser
    print("\nquit browser..")
    browser.quit()

@pytest.mark.parametrize('page_num', [236895, 236896, 236897, 236898, 236899, 236903, 236904, 236905])
def test_solve_task(browser, page_num):
    link = f"https://stepik.org/lesson/{page_num}/step/1"
    browser.get(link)

    answer = math.log(int(time.time()))
    input_area = WebDriverWait(browser, 10).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, "textarea.ember-text-area.ember-view.string-quiz__textarea"))
    )
    input_area.send_keys(str(answer))


    submit_btn = WebDriverWait(browser, 10).until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, 'button.submit-submission'))
    )
    submit_btn.click()

    res_msg = ''
    message_popup = WebDriverWait(browser, 10).until(
        EC.presence_of_element_located((By.CSS_SELECTOR,'pre.smart-hints__hint'))
    )
    res_msg = message_popup.text

    assert res_msg == 'Correct!'