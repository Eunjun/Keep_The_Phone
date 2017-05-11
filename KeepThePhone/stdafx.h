// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <mutex>
#include <functional>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

#define WINDOW_W	800
#define WINDOW_H	600

#include "GameEngine.h"
