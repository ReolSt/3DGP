cbuffer Camera : register(b1)
{
	matrix view : packoffset(c0);
	matrix projection : packoffset(c4);
	float3 position : packoffset(c8);
}

cbuffer Object : register(b2)
{
	matrix localToWorld : packoffset(c0);
}