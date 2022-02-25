import pytest

# Example for marking tests

@pytest.mark.xfail(strict=True) # fail test if it starts to pass
def test_succeed():
    assert True


@pytest.mark.xfail
def test_not_succeed():
    assert False


@pytest.mark.skip
def test_skipped():
    assert False