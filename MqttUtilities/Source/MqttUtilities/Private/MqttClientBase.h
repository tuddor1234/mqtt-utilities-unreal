// Copyright (c) 2019 Nineva Studios

#pragma once

#include "Interface/MqttClientInterface.h"

#include "MqttClientBase.generated.h"

UCLASS()
class UMqttClientBase : public UObject, public IMqttClientInterface
{
	GENERATED_BODY()

public:

	virtual ~UMqttClientBase();

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void Connect(FMqttConnectionData connectionData, const FOnConnectDelegate& onConnectCallback) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void Disconnect(const FOnDisconnectDelegate& onDisconnectCallback) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void Subscribe(FString topic, int qos) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void Unsubscribe(FString topic) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void Publish(FMqttMessage message) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void SetOnPublishHandler(const FOnPublishDelegate& onPublishCallback) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void SetOnMessageHandler(const FOnMessageDelegate& onMessageCallback) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void SetOnSubscribeHandler(const FOnSubscribeDelegate& onSubscribeCallback) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void SetOnUnsubscribeHandler(const FOnUnsubscribeDelegate& onUnsubscribeCallback) override;

	UFUNCTION(BlueprintCallable, Category = "MQTT")
	virtual void SetOnErrorHandler(const FOnMqttErrorDelegate& onErrorCallback) override;

public:

	/** Initialize MQTT client (for internal use only) */
	virtual void Init(FMqttClientConfig configData);

protected:

  UPROPERTY()
    FOnConnectDelegate OnConnectDelegate;
	UPROPERTY()
    FOnDisconnectDelegate OnDisconnectDelegate;
	UPROPERTY()
    FOnPublishDelegate OnPublishDelegate;
	UPROPERTY()
    FOnMessageDelegate OnMessageDelegate;
	UPROPERTY()
    FOnSubscribeDelegate OnSubscribeDelegate;
	UPROPERTY()
    FOnUnsubscribeDelegate OnUnsubscribeDelegate;
	UPROPERTY()
		FOnMqttErrorDelegate OnErrorDelegate;
};
