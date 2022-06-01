#include "ConstantBuffers.hlsl"

struct PSInput
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

PSInput main(float3 position : POSITION, float3 normal: NORMAL, float2 uv : UV)
{
	PSInput result;

	float3 positionW = (float3)mul(float4(position, 1.0f), localToWorld);
	result.position = mul(mul(float4(positionW, 1.0f), view), projection);
	result.color = float4(normal, 1.0f);

	return result;
}