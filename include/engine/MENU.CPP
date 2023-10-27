#include "Menu.h"

void Menu::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(backgroundSprite, states);
    target.draw(playText, states);
    target.draw(loadLevelText, states);
    target.draw(settingsText, states);
    target.draw(exitText, states);
}

Menu::Menu(unsigned int width, unsigned int height, unsigned int fontSize, string backgroundImagePath)
{
    this->fontSize = fontSize;
	setPosition(width, height);
    inMenuMode = true;
	setMenu();
    selectedItem = 0;
    menuItems = {&playText, &loadLevelText, &settingsText, &exitText};
    buttonScaleVector = Vector2f(1.35f, 1.35f);
    setColors(Color::White, Color::Cyan);
    if (!loadBackground(backgroundImagePath)) {
        cerr << "Error loading background image" << endl;
    }
}

void Menu::setPosition(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
}

void Menu::setMenu()
{
    if (loadFont()) {
        setMenuText();
        setMenuTextSize();
        setMenuTextFillColors();
        setMenuTextOrigins();
        setMenuTextPositions();
    }
}

bool Menu::loadFont()
{
    if (!font.loadFromFile("assets/font/font.ttf")) {
        cerr << "Error loading font" << endl;
        return false;
    }
    return true;
}

bool Menu::loadBackground(string path)
{
    if (!backgroundTexture.loadFromFile(path)) {
        return false;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    return true;
}

void Menu::setMenuText()
{
    playText.setFont(font);
    loadLevelText.setFont(font);
    settingsText.setFont(font);
    exitText.setFont(font);
    playText.setString("Play");
    loadLevelText.setString("Load Level");
    settingsText.setString("Settings");
    exitText.setString("Exit");
}

void Menu::setMenuTextSize()
{
    playText.setCharacterSize(fontSize);
    settingsText.setCharacterSize(fontSize);
    exitText.setCharacterSize(fontSize);
    loadLevelText.setCharacterSize(fontSize);
}

void Menu::setMenuTextFillColors()
{
    playText.setFillColor(selectedItemColor);
    settingsText.setFillColor(color);
    exitText.setFillColor(color);
    loadLevelText.setFillColor(color);
}

void Menu::setColors(Color regularColor, Color selectedItemColor)
{
    this->selectedItemColor = selectedItemColor;
    this->color = regularColor;
}

void Menu::restartMenuItems()
{
    setSelectedItem(0);
    for (int i = 1; i < menuItems.size(); i++) {
        menuItems[i]->setFillColor(color);
        menuItems[i]->setScale(Vector2f(1.0f, 1.0f));
    }
    menuItems[0]->setFillColor(selectedItemColor);
    menuItems[0]->setScale(buttonScaleVector);
}

void Menu::setSelectedItem(int itemID)
{
    this->selectedItem = itemID;
}


void Menu::setMenuTextOrigins()
{
    FloatRect textRect = playText.getLocalBounds();
    playText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
    textRect = settingsText.getLocalBounds();
    settingsText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    textRect = exitText.getLocalBounds();
    exitText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    textRect = loadLevelText.getLocalBounds();
    loadLevelText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
}

void Menu::setMenuTextPositions()
{
    float centerX = width / 2;
    float centerY = height / 2;
    float buttonSpacing = 100.0f;

    playText.setPosition(centerX, centerY - 150);
    loadLevelText.setPosition(centerX, centerY - 150 + buttonSpacing);
    settingsText.setPosition(centerX, centerY - 150 + 2 * buttonSpacing);
    exitText.setPosition(centerX, centerY - 150 + 3 * buttonSpacing);
}

void Menu::handleKeyPress(Keyboard::Key key)
{
    if (key == Keyboard::W || key == Keyboard::Up) {
        if (selectedItem > 0) {
            menuItems[selectedItem]->setFillColor(color);
            menuItems[selectedItem]->setScale(Vector2f(1.0f, 1.0f));
            selectedItem--;
            menuItems[selectedItem]->setFillColor(selectedItemColor);
            menuItems[selectedItem]->setScale(buttonScaleVector);
        }
    }
    else if (key == Keyboard::S || key == Keyboard::Down) {
        if (selectedItem < menuItems.size() - 1) {
            menuItems[selectedItem]->setFillColor(color);
            menuItems[selectedItem]->setScale(Vector2f(1.0f, 1.0f));
            selectedItem++;
            menuItems[selectedItem]->setFillColor(selectedItemColor);
            menuItems[selectedItem]->setScale(buttonScaleVector);
        }
    }
    else if (key == Keyboard::Return || key == Keyboard::Space) {
        handleMenuSelection();
    }
}

void Menu::handleMenuSelection()
{
    switch (selectedItem) {
    case 0:
        inMenuMode = false;
        break;
    case 1:
        cout << "Load Level" << endl;
        break;
    case 2:
        cout << "Settings" << endl;
        break;
    case 3:
        exit(0);
        break;
    }
}



