﻿#pragma once
#include <vector>
#include "..\Common\DeviceResources.h"
#include "ShaderStructures.h"
#include "..\Common\StepTimer.h"


namespace DX11UWA
{
	// This sample renderer instantiates a basic rendering pipeline.
	class Sample3DSceneRenderer
	{
	public:
		//FUNCTIONS
		bool loadOBJ(const char * path, std::vector<VertexPositionUVNormal> &vpuvn, std::vector<unsigned int> &outIndices);
		Sample3DSceneRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		//void Sample3DSceneRenderer::CreateVP(void);
		inline bool IsTracking(void) { return m_tracking; }
		void CreateWindowSizeDependentResources(void);
		void ReleaseDeviceDependentResources(void);
		void CreateDeviceDependentResources(void);
		void Update(DX::StepTimer const& timer);
		void TrackingUpdate(float positionX);
		void StartTracking(void);
		void StopTracking(void);
		void Render(void);
		// Helper functions for keyboard and mouse input
		void SetKeyboardButtons(const char* list);
		void SetMousePosition(const Windows::UI::Input::PointerPoint^ pos);
		void SetInputDeviceData(const char* kb, const Windows::UI::Input::PointerPoint^ pos);
	private:
		void Rotate(float radians);
		void UpdateCamera(DX::StepTimer const& timer, float const moveSpd, float const rotSpd);

	private:
		//RESOURCES
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;
		// Direct3D resources for cube geometry.
		Microsoft::WRL::ComPtr<ID3D11VertexShader>	m_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>	m_pixelShader;
		//MULTIPLE
		ModelViewProjectionConstantBuffer	m_constantBufferData;
		Microsoft::WRL::ComPtr<ID3D11InputLayout>	m_inputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		m_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		m_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		m_constantBuffer;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> pengSRV;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> pengTexture;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> pengSS;
		uint32	m_indexCount;
		//pyramid vars
		Microsoft::WRL::ComPtr<ID3D11VertexShader>	pyramidVertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>	pyramidPixelShader;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		pyramidConstantBuffer;
		Microsoft::WRL::ComPtr<ID3D11InputLayout>	pyramidInputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		pyramidIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>	pyramidVertexBuffer;
		ModelViewProjectionConstantBuffer	pyramidConstantBufferData;
		uint32	pyramidIndexCount;
		//geometry shader 
		Microsoft::WRL::ComPtr<ID3D11GeometryShader>	GeometryShader;
		//plane vars
		Microsoft::WRL::ComPtr<ID3D11Buffer>	planeConstantBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>	planeVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> planeIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11InputLayout>	planeInputLayout;
		ModelViewProjectionConstantBuffer planeConstantBufferData;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> planeSRV;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> planeTexture;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> planeSS;
		uint32	planeIndexCount;
		 
		//SKYBOX VARIABLES
		Microsoft::WRL::ComPtr<ID3D11VertexShader>	skyBoxVertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>	skyboxPixelShader;

		// Variables used with the rendering loop.
		bool	m_loadingComplete;
		float	m_degreesPerSecond;
		bool	m_tracking;

		// Data members for keyboard and mouse input
		char m_kbuttons[256];
		Windows::UI::Input::PointerPoint^ m_currMousePos;
		Windows::UI::Input::PointerPoint^ m_prevMousePos;

		// Matrix data member for the camera
		DirectX::XMFLOAT4X4 m_camera;
	};
}

