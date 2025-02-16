// Copyright (c) 2019 Nineva Studios

#pragma once

#include "MqttClientBase.h"
#include "CoreMinimal.h"

#include "MqttClient.generated.h"

class FMqttRunnable;

UCLASS()
class UMqttClient : public UMqttClientBase
{
	GENERATED_BODY()

	friend class FMqttRunnable;

public:
	virtual void BeginDestroy() override;

	virtual void Connect(FMqttConnectionData connectionData, const FOnConnectDelegate& onConnectCallback) override;

	virtual void Disconnect(const FOnDisconnectDelegate& onDisconnectCallback) override;

	virtual void Subscribe(FString topic, int qos) override;

	virtual void Unsubscribe(FString topic) override;

	virtual void Publish(FMqttMessage message) override;

public:
	virtual void Init(FMqttClientConfig configData) override;

private:

	FMqttRunnable* Task;
	FRunnableThread* Thread;
	FMqttClientConfig ClientConfig;
};