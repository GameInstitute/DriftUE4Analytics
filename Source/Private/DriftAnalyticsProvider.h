/**
* This file is part of the Drift Unreal Engine Integration.
*
* Copyright (C) 2016-2017 Directive Games Limited. All Rights Reserved.
*
* Licensed under the MIT License (the "License");
*
* You may not use this file except in compliance with the License.
* You may obtain a copy of the license in the LICENSE file found at the top
* level directory of this module, and at https://mit-license.org/
*/

#pragma once

#include "IAnalyticsProvider.h"


class IDriftAPI;


class FDriftAnalyticsProvider : public IAnalyticsProvider
{
public:
	FDriftAnalyticsProvider();

	// IAnalyticsProvider

	bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;
	void EndSession() override;
	void FlushEvents() override;

	void SetUserID(const FString& InUserID) override;
	FString GetUserID() const override;

    void SetBuildInfo(const FString& InBuildInfo) override;
    void SetGender(const FString& InGender) override;
    void SetLocation(const FString& InLocation) override;
    void SetAge(const int32 InAge) override;
    
    FString GetSessionID() const override;
	bool SetSessionID(const FString& InSessionID) override;

    using IAnalyticsProvider::RecordEvent;
    void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

    void RecordItemPurchase(const FString& ItemId, const FString& Currency, int PerItemCost, int ItemQuantity) override;
    void RecordItemPurchase(const FString& ItemId, int ItemQuantity, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;

    void RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const FString& RealCurrencyType, float RealMoneyCost, const FString& PaymentProvider) override;
    void RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;

    void RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;

    void RecordError(const FString& Error, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    
    void RecordProgress(const FString& ProgressType, const TArray<FString>& ProgressHierarchy, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;

    ~FDriftAnalyticsProvider();

private:
    IDriftAPI* GetDrift();
};
