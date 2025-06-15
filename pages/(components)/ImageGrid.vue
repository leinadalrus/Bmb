<script setup lang="ts">
import TradingCard, { type TradingCardMutationType } from './TradingCard.vue'

defineProps<{
    tradingCards: TradingCardMutationType[]
}>()
</script>

<template>
    <section>
        <article>
            <div>
                <li>
                    <TradingCard :trading-cards="tradingCards" />
                </li>
            </div>
        </article>
    </section>
</template>
