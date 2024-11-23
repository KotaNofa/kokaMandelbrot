#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size = { pixelWidth, pixelHeight };
	m_aspectRatio = pixelHeight / pixelWidth;
	m_plane_center = { 0, 0 };
	m_plane_size = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = State::CALCULATING;
	
	VertexArray va(Points);
	va.resize(pixelWidth * pixelHeight);
	m_vArray = va;
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray);
}

// TODO: defining the rest of the member functions

void ComplexPlane::updateRender()
{
	if (m_state == State::CALCULATING)
	{
		for (int i = 0; i < m_plane_size.y; i++)
		{
			for (int j = 0; j < m_plane_size.x; i++)
			{
				m_vArray[j + i * m_pixel_size.x].position = { (float)j, (float)i };
				Vector2f coords = mapPixelToCoords({ j, i });
				int iters = countIterations(coords);
				Uint8 r, g, b;
				iterationsToRGB(iters, r, g, b);
				m_vArray[j + i * m_pixel_size.x].color = { r, g, b };
			}
		}

		m_state = State::DISPLAYING;
	}
}

void ComplexPlane::zoomIn()
{
	m_zoomCount++;
	float x_size = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
	float y_size = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
	m_plane_size = { x_size, y_size };
	m_state = State::CALCULATING;
}

void ComplexPlane::zoomOut()
{
	m_zoomCount--;
	float x_size = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
	float y_size = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
	m_plane_size = { x_size, y_size };
	m_state = State::CALCULATING;
}

void ComplexPlane::setCenter(Vector2i mousePixel)
{
	m_plane_center = mapPixelToCoords(mousePixel);
	m_state = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
	m_mouseLocation = mapPixelToCoords(mousePixel);
}

void ComplexPlane::loadText(Text& text)
{
	string title = "Mandelbrot Set\n";
	string center = "Center: (" + to_string(m_plane_center.x) + ", " + to_string(m_plane_center.y) + ")\n";
	string cursor = "Cursor: (" + to_string(m_mouseLocation.x) + ", " + to_string(m_mouseLocation.y) + ")\n";
	string leftClick = "Left-click to Zoom in\n";
	string rightClick = "Right-click to Zoom out\n";

	text.setString(title + center + cursor + leftClick + rightClick);
}

size_t ComplexPlane::countIterations(Vector2f coord)
{
	size_t iters = -1;
	// TODO: IMPLEMENT THIS MEMBER FUNCTION
	cout << "countIterations(): To be implemented..." << endl;
	return iters;
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
	// TODO: IMPLEMENT THIS MEMBER FUNCTION
	cout << "iterationsToRGB(): To be implemented..." << endl;
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
	// TODO: IMPLEMENT THIS MEMBER FUNCTION
	cout << "mapPixelToCoords(): To be implemented..." << endl;
	return Vector2f(-1.0, -1.0);
}