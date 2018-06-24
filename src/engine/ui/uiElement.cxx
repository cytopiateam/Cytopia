#include "uiElement.hxx"

UiElement::UiElement(int x, int y, int uiSpriteID, int groupID, int actionID, int parentOfGroup)
    : _screenCoordinates({x, y, 0, 0}), _groupID(groupID), _actionID(actionID), _parentOf(parentOfGroup),
      _uiElementType("ImageButton")
{
  _texture = TextureManager::Instance().getUITexture(uiSpriteID);
  SDL_QueryTexture(_texture, NULL, NULL, &_width, &_height);
}

UiElement::UiElement(int x, int y, const std::string &text, int groupID, int actionID, int parentOfGroup)
    : _screenCoordinates({x, y, 0, 0}), _groupID(groupID), _actionID(actionID), _parentOf(parentOfGroup)
{
  drawText(text, _color);
}

UiElement::UiElement(int x, int y, int w, int h, int groupID, int actionID, int parentOfGroup)
    : _screenCoordinates({x, y, 0, 0}), _width(w), _height(h), _groupID(groupID), _actionID(actionID), _parentOf(parentOfGroup)
{
}

void UiElement::draw() 
{ 
  if (_texture)
  {
    renderTexture(); 
  }
}

void UiElement::changeTexture(int tileID) { _texture = TextureManager::Instance().getUITexture(tileID); }

void UiElement::renderTexture()
{
  if (_texture)
  {
    _destRect.x = _screenCoordinates.x;
    _destRect.y = _screenCoordinates.y;
    _destRect.w = _width;
    _destRect.h = _height;
    SDL_RenderCopy(_renderer, _texture, nullptr, &_destRect);
  }
}

bool UiElement::isClicked(int x, int y)
{
  if (x > _screenCoordinates.x && x < _screenCoordinates.x + _width && y > _screenCoordinates.y && y < _screenCoordinates.y + _height)
  {
    LOG() << "CLICKED";
    return true;
  }
  return false;
}

void UiElement::drawTextAt(int x, int y, const std::string &textureText, const SDL_Color &textColor)
{

}

void UiElement::drawText(const std::string &textureText, const SDL_Color &textColor)
{
  _font = TTF_OpenFont("resources/fonts/arcadeclassics.ttf", 20);

  if (!_font)
  {
    LOG(LOG_ERROR) << "Failed to load font!\n" << TTF_GetError();
  }

  SDL_Surface *textSurface = TTF_RenderText_Solid(_font, textureText.c_str(), textColor);
  if (textSurface)
  {
    if (_width == 0 && _height == 0)
    {
      _width = textSurface->w;
      _height = textSurface->h;
    }

    // If there's already an existing surface (like a button) blit the text to it.
    if (_surface)
    {
      // Center the text in the surface
      SDL_Rect textLocation = {0, 0, 0, 0};
      textLocation.x = (_surface->w / 2) - (_width / 2);
      textLocation.y = (_surface->h / 2) - (_height / 2);
      SDL_BlitSurface(textSurface, NULL, _surface, &textLocation);
      _texture = SDL_CreateTextureFromSurface(_renderer, _surface);

      return;
    }
    // else just create a new text texture
    else
    {
      _texture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    }

    if (!_texture)
    {
      LOG(LOG_ERROR) << "Failed to create texture from text surface!\n" << SDL_GetError();
    }
    //Delete no longer needed surface
    SDL_FreeSurface(textSurface);
  }
  else
  {
    LOG(LOG_ERROR) << "Failed to create text surface!\n" << TTF_GetError();
  }

  TTF_CloseFont(_font);
}

void UiElement::drawSolidRect(SDL_Rect rect, const SDL_Color &color)
{

  SDL_Renderer* renderer = Resources::getRenderer();
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(renderer, &rect);

}

void UiElement::drawLine(int x1, int y1, int x2, int y2, const SDL_Color &color)
{
  SDL_Renderer* renderer = Resources::getRenderer();
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}