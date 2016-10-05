#pragma once
const int width = 640;
const int height = 480;

//color = (Red, Green, Blue)
float *pixels = new float[width * height * 3];
//float *pixels = (float*)malloc(sizeof(float)*width*height * 3);
void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i1 > i0) {
		if (j1 >= j0) {
			for (int i = i0; i <= i1; i++)
			{
				const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

				drawPixel(i, j, red, green, blue);
			}
		}
		else {
			for (int i = i0; i <= i1; i++)
			{
				const int j = j0 - (j0 - j1)*(i - i0) / (i1 - i0);

				drawPixel(i, j, red, green, blue);
			}
		}
	}
	else if (i1 < i0) {
		if (j1 >= j0) {
			for (int i = i1; i <= i0; i++)
			{
				const int j = j1 - (j1 - j0)*(i - i1) / (i0 - i1);
				drawPixel(i, j, red, green, blue);
			}
		}
		else {
			for (int i = i1; i <= i0; i++)
			{
				const int j = j1 + (j0 - j1)*(i - i1) / (i0 - i1);

				drawPixel(i, j, red, green, blue);
			}
		}
	}
	else {
		for (int j = j0; j <= j1; j++) {
			drawPixel(i0, j, 1.0f, 0.0f, 0.0f);
		}
	}
}