#pragma once

struct CameraBuffer
{
	Matrix matView = Matrix::Identity;
	Matrix matProjection = Matrix::Identity;
};

struct TransformBuffer
{
	Matrix matWorld = Matrix::Identity;
};

// 16 바이트 단위로 데이터의 크기가 정해져야 한다.
// ex)최소 16바이트
//    그 다음 부터는 16 바이트의 배수로 적용되어야 함.
struct ColorBuffer
{
	Color color = Color(0, 0, 0, 1);
	BOOL isConflict = false;
	int  dummy[3] = { 0, };
};

struct TextureBuffer
{
	Vec2 offset;
	Vec2 dummy;
};

struct AnimationBuffer
{
	Vec2 sprite_offset;
	Vec2 sprite_size;
	Vec2 texture_size;
	float is_animated;
	float padding; //16 바이트 기준의  animation.hlsl의  AnimationBuffer와 크기를 맞춰주기 위한 더미
};
