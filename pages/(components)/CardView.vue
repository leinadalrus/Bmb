<script setup lang="ts">
import TradingCard from './TradingCard.vue'
</script>

<template>
    <section
        class="grid grid-cols-1 grid-rows-[repeat(auto-fit,_minmax(12.5rem,_1fr))] gap-4"
    >
        <TradingCard
            title="Hello World!"
            author="Chicken"
            group="Chickens"
            content="
                    'Lorem ipsum dolor sit amet, \
                            consectetur adipiscing elit, \
                            sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
                "
            flavour="
                    'Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.'
                "
            image=""
            tags=""
        />
    </section>
</template>
