#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size = { pixelWidth, pixelHeight };
	m_aspectRatio = (float)pixelHeight / pixelWidth;
	m_plane_center = { 0.0f, 0.0f };
	m_plane_size = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = State::CALCULATING;
	
	VertexArray va(Points);
	va.resize(pixelWidth * pixelHeight);
	m_vArray = va;
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray, states);
}

void ComplexPlane::updateRender()
{
	if (m_state == State::CALCULATING)
	{
		// Adjust vertex array size
		m_vArray.resize(m_pixel_size.x * m_pixel_size.y);

		for (int i = 0; i < m_pixel_size.y; i++)
		{
			for (int j = 0; j < m_pixel_size.x; j++)
			{
				size_t index = j + i * m_pixel_size.x;
				m_vArray[index].position = { (float)j, (float)i };

				Vector2f coords = mapPixelToCoords({ j, i });
				size_t iters = countIterations(coords);

				Uint8 r, g, b;
				iterationsToRGB(iters, r, g, b);
				m_vArray[index].color = { r, g, b };
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
	string zoomLevel = "Zoom Level: " + to_string(m_zoomCount) + "\n";
	string leftClick = "Left-click to Zoom in\n";
	string rightClick = "Right-click to Zoom out\n";

	text.setString(title + center + cursor + zoomLevel + leftClick + rightClick);
}

size_t ComplexPlane::countIterations(Vector2f coord)
{
	complex<double> c(coord.x, coord.y);
	complex<double> z = c;
	size_t iters = 0;

	double magnitude_squared = 0.0;

	while (magnitude_squared < 4.0 && iters < MAX_ITER)
	{
		z = z * z + c;
		magnitude_squared = norm(z);
		iters++;
	}

	return iters;
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
	if (count == MAX_ITER)
	{
		// Set to black for points inside the Mandelbrot set
		r = g = b = 0;
	}
	else
	{
		// Normalize the iteration count to [0, 1]
		float t = static_cast<float>(count) / MAX_ITER;
		// Map the normalized value to grayscale intensity
		Uint8 intensity = static_cast<Uint8>(255 * t);
		// Apply the intensity to all color channels
		r = g = b = intensity;
	}
}


Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
	Vector2f coords;

	coords.x = m_plane_center.x + ((float)mousePixel.x / m_pixel_size.x - 0.5f) * m_plane_size.x;
	coords.y = m_plane_center.y + ((float)mousePixel.y / m_pixel_size.y - 0.5f) * m_plane_size.y;

	return coords;
}