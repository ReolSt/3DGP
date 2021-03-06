struct PSInput
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

PSInput VSMain(float3 position : POSITION, float3 normal : NORMAL)
{
	PSInput result;

	result.position = mul(mul(mul(float4(position, 1.0f), localToWorld), view), projection);
	result.color = float4(normal, 1.0f);

	return result;
}

float4 PSMain(PSInput input) : SV_TARGET
{
	return input.color;
}

