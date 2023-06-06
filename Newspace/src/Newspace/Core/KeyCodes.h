#pragma once

namespace Newspace
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define HZ_KEY_SPACE           ::Newspace::Key::Space
#define HZ_KEY_APOSTROPHE      ::Newspace::Key::Apostrophe    /* ' */
#define HZ_KEY_COMMA           ::Newspace::Key::Comma         /* , */
#define HZ_KEY_MINUS           ::Newspace::Key::Minus         /* - */
#define HZ_KEY_PERIOD          ::Newspace::Key::Period        /* . */
#define HZ_KEY_SLASH           ::Newspace::Key::Slash         /* / */
#define HZ_KEY_0               ::Newspace::Key::D0
#define HZ_KEY_1               ::Newspace::Key::D1
#define HZ_KEY_2               ::Newspace::Key::D2
#define HZ_KEY_3               ::Newspace::Key::D3
#define HZ_KEY_4               ::Newspace::Key::D4
#define HZ_KEY_5               ::Newspace::Key::D5
#define HZ_KEY_6               ::Newspace::Key::D6
#define HZ_KEY_7               ::Newspace::Key::D7
#define HZ_KEY_8               ::Newspace::Key::D8
#define HZ_KEY_9               ::Newspace::Key::D9
#define HZ_KEY_SEMICOLON       ::Newspace::Key::Semicolon     /* ; */
#define HZ_KEY_EQUAL           ::Newspace::Key::Equal         /* = */
#define HZ_KEY_A               ::Newspace::Key::A
#define HZ_KEY_B               ::Newspace::Key::B
#define HZ_KEY_C               ::Newspace::Key::C
#define HZ_KEY_D               ::Newspace::Key::D
#define HZ_KEY_E               ::Newspace::Key::E
#define HZ_KEY_F               ::Newspace::Key::F
#define HZ_KEY_G               ::Newspace::Key::G
#define HZ_KEY_H               ::Newspace::Key::H
#define HZ_KEY_I               ::Newspace::Key::I
#define HZ_KEY_J               ::Newspace::Key::J
#define HZ_KEY_K               ::Newspace::Key::K
#define HZ_KEY_L               ::Newspace::Key::L
#define HZ_KEY_M               ::Newspace::Key::M
#define HZ_KEY_N               ::Newspace::Key::N
#define HZ_KEY_O               ::Newspace::Key::O
#define HZ_KEY_P               ::Newspace::Key::P
#define HZ_KEY_Q               ::Newspace::Key::Q
#define HZ_KEY_R               ::Newspace::Key::R
#define HZ_KEY_S               ::Newspace::Key::S
#define HZ_KEY_T               ::Newspace::Key::T
#define HZ_KEY_U               ::Newspace::Key::U
#define HZ_KEY_V               ::Newspace::Key::V
#define HZ_KEY_W               ::Newspace::Key::W
#define HZ_KEY_X               ::Newspace::Key::X
#define HZ_KEY_Y               ::Newspace::Key::Y
#define HZ_KEY_Z               ::Newspace::Key::Z
#define HZ_KEY_LEFT_BRACKET    ::Newspace::Key::LeftBracket   /* [ */
#define HZ_KEY_BACKSLASH       ::Newspace::Key::Backslash     /* \ */
#define HZ_KEY_RIGHT_BRACKET   ::Newspace::Key::RightBracket  /* ] */
#define HZ_KEY_GRAVE_ACCENT    ::Newspace::Key::GraveAccent   /* ` */
#define HZ_KEY_WORLD_1         ::Newspace::Key::World1        /* non-US #1 */
#define HZ_KEY_WORLD_2         ::Newspace::Key::World2        /* non-US #2 */

/* Function keys */
#define HZ_KEY_ESCAPE          ::Newspace::Key::Escape
#define HZ_KEY_ENTER           ::Newspace::Key::Enter
#define HZ_KEY_TAB             ::Newspace::Key::Tab
#define HZ_KEY_BACKSPACE       ::Newspace::Key::Backspace
#define HZ_KEY_INSERT          ::Newspace::Key::Insert
#define HZ_KEY_DELETE          ::Newspace::Key::Delete
#define HZ_KEY_RIGHT           ::Newspace::Key::Right
#define HZ_KEY_LEFT            ::Newspace::Key::Left
#define HZ_KEY_DOWN            ::Newspace::Key::Down
#define HZ_KEY_UP              ::Newspace::Key::Up
#define HZ_KEY_PAGE_UP         ::Newspace::Key::PageUp
#define HZ_KEY_PAGE_DOWN       ::Newspace::Key::PageDown
#define HZ_KEY_HOME            ::Newspace::Key::Home
#define HZ_KEY_END             ::Newspace::Key::End
#define HZ_KEY_CAPS_LOCK       ::Newspace::Key::CapsLock
#define HZ_KEY_SCROLL_LOCK     ::Newspace::Key::ScrollLock
#define HZ_KEY_NUM_LOCK        ::Newspace::Key::NumLock
#define HZ_KEY_PRINT_SCREEN    ::Newspace::Key::PrintScreen
#define HZ_KEY_PAUSE           ::Newspace::Key::Pause
#define HZ_KEY_F1              ::Newspace::Key::F1
#define HZ_KEY_F2              ::Newspace::Key::F2
#define HZ_KEY_F3              ::Newspace::Key::F3
#define HZ_KEY_F4              ::Newspace::Key::F4
#define HZ_KEY_F5              ::Newspace::Key::F5
#define HZ_KEY_F6              ::Newspace::Key::F6
#define HZ_KEY_F7              ::Newspace::Key::F7
#define HZ_KEY_F8              ::Newspace::Key::F8
#define HZ_KEY_F9              ::Newspace::Key::F9
#define HZ_KEY_F10             ::Newspace::Key::F10
#define HZ_KEY_F11             ::Newspace::Key::F11
#define HZ_KEY_F12             ::Newspace::Key::F12
#define HZ_KEY_F13             ::Newspace::Key::F13
#define HZ_KEY_F14             ::Newspace::Key::F14
#define HZ_KEY_F15             ::Newspace::Key::F15
#define HZ_KEY_F16             ::Newspace::Key::F16
#define HZ_KEY_F17             ::Newspace::Key::F17
#define HZ_KEY_F18             ::Newspace::Key::F18
#define HZ_KEY_F19             ::Newspace::Key::F19
#define HZ_KEY_F20             ::Newspace::Key::F20
#define HZ_KEY_F21             ::Newspace::Key::F21
#define HZ_KEY_F22             ::Newspace::Key::F22
#define HZ_KEY_F23             ::Newspace::Key::F23
#define HZ_KEY_F24             ::Newspace::Key::F24
#define HZ_KEY_F25             ::Newspace::Key::F25

/* Keypad */
#define HZ_KEY_KP_0            ::Newspace::Key::KP0
#define HZ_KEY_KP_1            ::Newspace::Key::KP1
#define HZ_KEY_KP_2            ::Newspace::Key::KP2
#define HZ_KEY_KP_3            ::Newspace::Key::KP3
#define HZ_KEY_KP_4            ::Newspace::Key::KP4
#define HZ_KEY_KP_5            ::Newspace::Key::KP5
#define HZ_KEY_KP_6            ::Newspace::Key::KP6
#define HZ_KEY_KP_7            ::Newspace::Key::KP7
#define HZ_KEY_KP_8            ::Newspace::Key::KP8
#define HZ_KEY_KP_9            ::Newspace::Key::KP9
#define HZ_KEY_KP_DECIMAL      ::Newspace::Key::KPDecimal
#define HZ_KEY_KP_DIVIDE       ::Newspace::Key::KPDivide
#define HZ_KEY_KP_MULTIPLY     ::Newspace::Key::KPMultiply
#define HZ_KEY_KP_SUBTRACT     ::Newspace::Key::KPSubtract
#define HZ_KEY_KP_ADD          ::Newspace::Key::KPAdd
#define HZ_KEY_KP_ENTER        ::Newspace::Key::KPEnter
#define HZ_KEY_KP_EQUAL        ::Newspace::Key::KPEqual

#define HZ_KEY_LEFT_SHIFT      ::Newspace::Key::LeftShift
#define HZ_KEY_LEFT_CONTROL    ::Newspace::Key::LeftControl
#define HZ_KEY_LEFT_ALT        ::Newspace::Key::LeftAlt
#define HZ_KEY_LEFT_SUPER      ::Newspace::Key::LeftSuper
#define HZ_KEY_RIGHT_SHIFT     ::Newspace::Key::RightShift
#define HZ_KEY_RIGHT_CONTROL   ::Newspace::Key::RightControl
#define HZ_KEY_RIGHT_ALT       ::Newspace::Key::RightAlt
#define HZ_KEY_RIGHT_SUPER     ::Newspace::Key::RightSuper
#define HZ_KEY_MENU            ::Newspace::Key::Menu
