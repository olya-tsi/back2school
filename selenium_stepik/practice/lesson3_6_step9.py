from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# Practice to test localization using coftest.py and command line parameters

link = "http://selenium1py.pythonanywhere.com/catalogue/coders-at-work_207/"

locale_names = {
    'ru': "Добавить в корзину",
    'en': "Add to basket",
    'fr': "Ajouter au panier"
}

def test_button_add_to_basket(browser, request):
    browser.get(link)

    submit_btn = WebDriverWait(browser, 10).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, "button.btn-add-to-basket"))
    )
    submit_btn_value = submit_btn.text
    expected = locale_names[request.config.getoption('language')]

    time.sleep(10)

    assert submit_btn_value == expected