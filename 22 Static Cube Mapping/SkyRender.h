#ifndef SKYRENDER_H
#define SKYRENDER_H

#include <vector>
#include <string>
#include "Effects.h"
#include "Camera.h"

class SkyRender
{
public:
	template<class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;


	// ��Ҫ�ṩ��������պ���ͼ ���� �Ѿ������õ���պ�����.dds�ļ�
	SkyRender(ComPtr<ID3D11Device> device, 
		ComPtr<ID3D11DeviceContext> deviceContext, 
		const std::wstring& cubemapFilename, 
		float skySphereRadius,		// �����뾶
		bool generateMips = false);	// Ĭ�ϲ�Ϊ��̬��պ�����mipmaps


	// ��Ҫ�ṩ��պе�������������ͼ
	SkyRender(ComPtr<ID3D11Device> device, 
		ComPtr<ID3D11DeviceContext> deviceContext, 
		const std::vector<std::wstring>& cubemapFilenames, 
		float skySphereRadius,		// �����뾶
		bool generateMips = false);	// Ĭ�ϲ�Ϊ��̬��պ�����mipmaps


	ComPtr<ID3D11ShaderResourceView> GetTextureCube();

	void Draw(ComPtr<ID3D11DeviceContext> deviceContext, SkyEffect& skyEffect, const Camera& camera);

private:
	void InitResource(ComPtr<ID3D11Device> device, float skySphereRadius);

private:
	ComPtr<ID3D11Buffer> mVertexBuffer;
	ComPtr<ID3D11Buffer> mIndexBuffer;

	UINT mIndexCount;

	ComPtr<ID3D11ShaderResourceView> mTextureCubeSRV;
};

#endif