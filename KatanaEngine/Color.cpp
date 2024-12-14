
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#include "KatanaEngine.h"

namespace KatanaEngine
{

	Color Color::Lerp(const Color& start, const Color& end, const float value)
	{
		if (value <= 0) return start;
		if (value >= 1) return end;

		float red = Math::Lerp(start.Red, end.Red, value);
		float green = Math::Lerp(start.Green, end.Green, value);
		float blue = Math::Lerp(start.Blue, end.Blue, value);
		float alpha = Math::Lerp(start.Alpha, end.Alpha, value);

		return Color(red, green, blue, alpha);
	}

	const Color Color::operator*(const float scalar) const
	{
		Color color = Color(*this);
		color.Red *= scalar;
		color.Green *= scalar;
		color.Blue *= scalar;
		color.Alpha *= scalar;
		return color;
	}

	bool Color::operator== (const Color& color) const
	{
		return ((Red == color.Red) && (Green == color.Green)
			&& (Blue == color.Blue) && (Alpha == color.Alpha));
	}

	bool Color::operator!= (const Color& color) const
	{
		return !((Red == color.Red) && (Green == color.Green)
			&& (Blue == color.Blue) && (Alpha == color.Alpha));
	}

	const Color Color::TRANSPARENT = Color(0.0f, 0.0f, 0.0f, 0.0f);

	const Color Color::ALICEBLUE = Color(0.94f, 0.97f, 1.0f);
	const Color Color::ANTIQUEWHITE = Color(0.98f, 0.92f, 0.84f);
	const Color Color::AQUA = Color(0.0f, 1.0f, 1.0f);
	const Color Color::AQUAMARINE = Color(0.5f, 1.0f, 0.83f);
	const Color Color::AZURE = Color(0.94f, 1.0f, 1.0f);
	const Color Color::BEIGE = Color(0.96f, 0.96f, 0.86f);
	const Color Color::BISQUE = Color(1.0f, 0.89f, 0.77f);
	const Color Color::BLACK = Color(0.0f, 0.0f, 0.0f);
	const Color Color::BLANCHEDALMOND = Color(1.0f, 0.92f, 0.8f);
	const Color Color::BLUE = Color(0.0f, 0.0f, 1.0f);
	const Color Color::BLUEVIOLET = Color(0.54f, 0.17f, 0.89f);
	const Color Color::BROWN = Color(0.65f, 0.16f, 0.16f);
	const Color Color::BURLYWOOD = Color(0.87f, 0.72f, 0.53f);
	const Color Color::CADETBLUE = Color(0.37f, 0.62f, 0.63f);
	const Color Color::CHARTREUSE = Color(0.5f, 1.0f, 0.0f);
	const Color Color::CHOCOLATE = Color(0.82f, 0.41f, 0.12f);
	const Color Color::CORAL = Color(1.0f, 0.5f, 0.31f);
	const Color Color::CORNFLOWER = Color(0.39f, 0.58f, 0.93f);
	const Color Color::CORNSILK = Color(1.0f, 0.97f, 0.86f);
	const Color Color::CRIMSON = Color(0.86f, 0.08f, 0.24f);
	const Color Color::CYAN = Color(0.0f, 1.0f, 1.0f);
	const Color Color::DARKBLUE = Color(0.0f, 0.0f, 0.55f);
	const Color Color::DARKCYAN = Color(0.0f, 0.55f, 0.55f);
	const Color Color::DARKGOLDENROD = Color(0.72f, 0.53f, 0.04f);
	const Color Color::DARKGRAY = Color(0.66f, 0.66f, 0.66f);
	const Color Color::DARKGREEN = Color(0.0f, 0.39f, 0.0f);
	const Color Color::DARKKHAKI = Color(0.74f, 0.72f, 0.42f);
	const Color Color::DARKMAGENTA = Color(0.55f, 0.0f, 0.55f);
	const Color Color::DARKOLIVEGREEN = Color(0.33f, 0.42f, 0.18f);
	const Color Color::DARKORANGE = Color(1.0f, 0.55f, 0.0f);
	const Color Color::DARKORCHID = Color(0.6f, 0.2f, 0.8f);
	const Color Color::DARKRED = Color(0.55f, 0.0f, 0.0f);
	const Color Color::DARKSALMON = Color(0.91f, 0.59f, 0.48f);
	const Color Color::DARKSEAGREEN = Color(0.56f, 0.74f, 0.56f);
	const Color Color::DARKSLATEBLUE = Color(0.28f, 0.24f, 0.55f);
	const Color Color::DARKSLATEGRAY = Color(0.18f, 0.31f, 0.31f);
	const Color Color::DARKTURQUOISE = Color(0.0f, 0.81f, 0.82f);
	const Color Color::DARKVIOLET = Color(0.58f, 0.0f, 0.83f);
	const Color Color::DEEPPINK = Color(1.0f, 0.08f, 0.58f);
	const Color Color::DEEPSKYBLUE = Color(0.0f, 0.75f, 1.0f);
	const Color Color::DIMGRAY = Color(0.41f, 0.41f, 0.41f);
	const Color Color::DODGERBLUE = Color(0.12f, 0.56f, 1.0f);
	const Color Color::FIREBRICK = Color(0.7f, 0.13f, 0.13f);
	const Color Color::FLORALWHITE = Color(1.0f, 0.98f, 0.94f);
	const Color Color::FORESTGREEN = Color(0.13f, 0.55f, 0.13f);
	const Color Color::FUCHSIA = Color(1.0f, 0.0f, 1.0f);
	const Color Color::GAINSBORO = Color(0.86f, 0.86f, 0.86f);
	const Color Color::GHOSTWHITE = Color(0.97f, 0.97f, 1.0f);
	const Color Color::GOLD = Color(1.0f, 0.84f, 0.0f);
	const Color Color::GOLDENROD = Color(0.85f, 0.65f, 0.13f);
	const Color Color::GRAY = Color(0.75f, 0.75f, 0.75f);
	const Color Color::WEBGRAY = Color(0.5f, 0.5f, 0.5f);
	const Color Color::GREEN = Color(0.0f, 1.0f, 0.0f);
	const Color Color::WEBGREEN = Color(0.0f, 0.5f, 0.0f);
	const Color Color::GREENYELLOW = Color(0.68f, 1.0f, 0.18f);
	const Color Color::HONEYDEW = Color(0.94f, 1.0f, 0.94f);
	const Color Color::HOTPINK = Color(1.0f, 0.41f, 0.71f);
	const Color Color::INDIANRED = Color(0.8f, 0.36f, 0.36f);
	const Color Color::INDIGO = Color(0.29f, 0.0f, 0.51f);
	const Color Color::IVORY = Color(1.0f, 1.0f, 0.94f);
	const Color Color::KHAKI = Color(0.94f, 0.9f, 0.55f);
	const Color Color::LAVENDER = Color(0.9f, 0.9f, 0.98f);
	const Color Color::LAVENDERBLUSH = Color(1.0f, 0.94f, 0.96f);
	const Color Color::LAWNGREEN = Color(0.49f, 0.99f, 0.0f);
	const Color Color::LEMONCHIFFON = Color(1.0f, 0.98f, 0.8f);
	const Color Color::LIGHTBLUE = Color(0.68f, 0.85f, 0.9f);
	const Color Color::LIGHTCORAL = Color(0.94f, 0.5f, 0.5f);
	const Color Color::LIGHTCYAN = Color(0.88f, 1.0f, 1.0f);
	const Color Color::LIGHTGOLDENROD = Color(0.98f, 0.98f, 0.82f);
	const Color Color::LIGHTGRAY = Color(0.83f, 0.83f, 0.83f);
	const Color Color::LIGHTGREEN = Color(0.56f, 0.93f, 0.56f);
	const Color Color::LIGHTPINK = Color(1.0f, 0.71f, 0.76f);
	const Color Color::LIGHTSALMON = Color(1.0f, 0.63f, 0.48f);
	const Color Color::LIGHTSEAGREEN = Color(0.13f, 0.7f, 0.67f);
	const Color Color::LIGHTSKYBLUE = Color(0.53f, 0.81f, 0.98f);
	const Color Color::LIGHTSLATEGRAY = Color(0.47f, 0.53f, 0.6f);
	const Color Color::LIGHTSTEELBLUE = Color(0.69f, 0.77f, 0.87f);
	const Color Color::LIGHTYELLOW = Color(1.0f, 1.0f, 0.88f);
	const Color Color::LIME = Color(0.0f, 1.0f, 0.0f);
	const Color Color::LIMEGREEN = Color(0.2f, 0.8f, 0.2f);
	const Color Color::LINEN = Color(0.98f, 0.94f, 0.9f);
	const Color Color::MAGENTA = Color(1.0f, 0.0f, 1.0f);
	const Color Color::MAROON = Color(0.69f, 0.19f, 0.38f);
	const Color Color::WEBMAROON = Color(0.5f, 0.0f, 0.0f);
	const Color Color::MEDIUMAQUAMARINE = Color(0.4f, 0.8f, 0.67f);
	const Color Color::MEDIUMBLUE = Color(0.0f, 0.0f, 0.8f);
	const Color Color::MEDIUMORCHID = Color(0.73f, 0.33f, 0.83f);
	const Color Color::MEDIUMPURPLE = Color(0.58f, 0.44f, 0.86f);
	const Color Color::MEDIUMSEAGREEN = Color(0.24f, 0.7f, 0.44f);
	const Color Color::MEDIUMSLATEBLUE = Color(0.48f, 0.41f, 0.93f);
	const Color Color::MEDIUMSPRINGGREEN = Color(0.0f, 0.98f, 0.6f);
	const Color Color::MEDIUMTURQUOISE = Color(0.28f, 0.82f, 0.8f);
	const Color Color::MEDIUMVIOLETRED = Color(0.78f, 0.08f, 0.52f);
	const Color Color::MIDNIGHTBLUE = Color(0.1f, 0.1f, 0.44f);
	const Color Color::MINTCREAM = Color(0.96f, 1.0f, 0.98f);
	const Color Color::MISTYROSE = Color(1.0f, 0.89f, 0.88f);
	const Color Color::MOCCASIN = Color(1.0f, 0.89f, 0.71f);
	const Color Color::NAVAJOWHITE = Color(1.0f, 0.87f, 0.68f);
	const Color Color::NAVYBLUE = Color(0.0f, 0.0f, 0.5f);
	const Color Color::OLDLACE = Color(0.99f, 0.96f, 0.9f);
	const Color Color::OLIVE = Color(0.5f, 0.5f, 0.0f);
	const Color Color::OLIVEDRAB = Color(0.42f, 0.56f, 0.14f);
	const Color Color::ORANGE = Color(1.0f, 0.65f, 0.0f);
	const Color Color::ORANGERED = Color(1.0f, 0.27f, 0.0f);
	const Color Color::ORCHID = Color(0.85f, 0.44f, 0.84f);
	const Color Color::PALEGOLDENROD = Color(0.93f, 0.91f, 0.67f);
	const Color Color::PALEGREEN = Color(0.6f, 0.98f, 0.6f);
	const Color Color::PALETURQUOISE = Color(0.69f, 0.93f, 0.93f);
	const Color Color::PALEVIOLETRED = Color(0.86f, 0.44f, 0.58f);
	const Color Color::PAPAYAWHIP = Color(1.0f, 0.94f, 0.84f);
	const Color Color::PEACHPUFF = Color(1.0f, 0.85f, 0.73f);
	const Color Color::PERU = Color(0.8f, 0.52f, 0.25f);
	const Color Color::PINK = Color(1.0f, 0.75f, 0.8f);
	const Color Color::PLUM = Color(0.87f, 0.63f, 0.87f);
	const Color Color::POWDERBLUE = Color(0.69f, 0.88f, 0.9f);
	const Color Color::PURPLE = Color(0.63f, 0.13f, 0.94f);
	const Color Color::WEBPURPLE = Color(0.5f, 0.0f, 0.5f);
	const Color Color::REBECCAPURPLE = Color(0.4f, 0.2f, 0.6f);
	const Color Color::RED = Color(1.0f, 0.0f, 0.0f);
	const Color Color::ROSYBROWN = Color(0.74f, 0.56f, 0.56f);
	const Color Color::ROYALBLUE = Color(0.25f, 0.41f, 0.88f);
	const Color Color::SADDLEBROWN = Color(0.55f, 0.27f, 0.07f);
	const Color Color::SALMON = Color(0.98f, 0.5f, 0.45f);
	const Color Color::SANDYBROWN = Color(0.96f, 0.64f, 0.38f);
	const Color Color::SEAGREEN = Color(0.18f, 0.55f, 0.34f);
	const Color Color::SEASHELL = Color(1.0f, 0.96f, 0.93f);
	const Color Color::SIENNA = Color(0.63f, 0.32f, 0.18f);
	const Color Color::SILVER = Color(0.75f, 0.75f, 0.75f);
	const Color Color::SKYBLUE = Color(0.53f, 0.81f, 0.92f);
	const Color Color::SLATEBLUE = Color(0.42f, 0.35f, 0.8f);
	const Color Color::SLATEGRAY = Color(0.44f, 0.5f, 0.56f);
	const Color Color::SNOW = Color(1.0f, 0.98f, 0.98f);
	const Color Color::SPRINGGREEN = Color(0.0f, 1.0f, 0.5f);
	const Color Color::STEELBLUE = Color(0.27f, 0.51f, 0.71f);
	const Color Color::TAN = Color(0.82f, 0.71f, 0.55f);
	const Color Color::TEAL = Color(0.0f, 0.5f, 0.5f);
	const Color Color::THISTLE = Color(0.85f, 0.75f, 0.85f);
	const Color Color::TOMATO = Color(1.0f, 0.39f, 0.28f);
	const Color Color::TURQUOISE = Color(0.25f, 0.88f, 0.82f);
	const Color Color::VIOLET = Color(0.93f, 0.51f, 0.93f);
	const Color Color::WHEAT = Color(0.96f, 0.87f, 0.7f);
	const Color Color::WHITE = Color(1.0f, 1.0f, 1.0f);
	const Color Color::WHITESMOKE = Color(0.96f, 0.96f, 0.96f);
	const Color Color::YELLOW = Color(1.0f, 1.0f, 0.0f);
	const Color Color::YELLOWGREEN = Color(0.6f, 0.8f, 0.2f);


}